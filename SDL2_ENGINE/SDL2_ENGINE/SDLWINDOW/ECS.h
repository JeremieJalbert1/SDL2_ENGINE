#pragma once
#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID newComponentTypeID()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template <typename T> inline ComponentID componentTypeID() noexcept
{
	static ComponentID typeID = newComponentTypeID();
	return typeID;
}

constexpr std::size_t MAXCOMPONENTS = 64;
constexpr std::size_t MAXGROUPS = 64;

using ComponentBitSet = std::bitset<MAXCOMPONENTS>;
using ComponentArray = std::array<Component*, MAXCOMPONENTS>;
using GroupBitSet = std::bitset<MAXGROUPS>;

class Component
{

public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};

class Entity
{
public:

	Entity(Manager& mManager) 
		: manager(mManager) 
	{}
	
	void update()
	{
		for (auto& c : components) c->update();
	}

	void draw() 
	{
		for (auto& c : components) c->draw();
	}

	bool isActive() const { return active; }
	void destroy() { active = false; }

	bool hasGroup(Group mGroup)
	{
		return groupBitSet[mGroup];
	}

	void addGroup(Group mGroup);
	void delGroup(Group mGroup)
	{
		groupBitSet[mGroup] = false;
	}

	template <typename T> bool hasComponent() const
	{
		return componentBitSet[componentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[componentTypeID<T>()] = c;
		componentBitSet[componentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template <typename T> T& component() const
	{
		auto ptr(componentArray[componentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	Manager & manager;
	bool active{ true };
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
	GroupBitSet groupBitSet;
};

using EntityVector = std::vector<std::unique_ptr<Entity>>;
using GroupVector = std::array<std::vector<Entity*>, MAXGROUPS>;

class Manager
{
public:
	void update()
	{
		for (auto& e : entities) e->update();
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	void refresh()
	{
		for (size_t i{ 0 }; i < MAXGROUPS; ++i)
		{
			auto& v(groupedEntities[i]);
			v.erase(std::remove_if(std::begin(v), std::end(v),
				[i]( Entity* mEntity)
				{
					return !mEntity->isActive() || !mEntity->hasGroup(i);
				}),
					std::end(v));
		}

		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}),
				std::end(entities));
	}

	void AddToGroup(Entity* mEntity, Group mGroup)
	{
		groupedEntities[mGroup].emplace_back(mEntity);
	}

	std::vector<Entity*>& getGroup(Group mGroup)
	{
		return groupedEntities[mGroup];
	}

	Entity& addEntity()
	{
		Entity* e = new Entity(*this);
		std::unique_ptr<Entity> uPtr{ e };

		entities.emplace_back(std::move(uPtr));

		return *e;
	}

private:
	EntityVector entities;
	GroupVector groupedEntities;
};

#endif // !ECS_H

