#pragma once

#include "Physics.hpp"

class Ground final{
private:
	constexpr static physx::PxReal DEFAULT_STATIC_FRICTION_ = 0.85f;
	constexpr static physx::PxReal DEFAULT_DYNAMIC_FRICTION_ = 0.8f;
	constexpr static physx::PxReal DEFAULT_RESTITUTION_ = 0.6f;

public:
	Ground() noexcept(false) = delete;
	Ground(const physx::PxTransform& transform) noexcept(false){
		transform_ = transform;
		initialize();
	}
	Ground(const Ground&) = delete;
	Ground(const Ground&&) = delete;
	const Ground& operator=(const Ground&) = delete;
	const Ground& operator=(const Ground&&) = delete;
	~Ground() noexcept = default;

private:
	physx::PxTransform transform_;

	physx::PxMaterial* material_ = nullptr;
	physx::PxShape* shape_ = nullptr;
	physx::PxRigidStatic* actor_ = nullptr;


public:
	physx::PxRigidStatic& getActor() const noexcept{
		return(*actor_);
	}

private:
	void initialize() noexcept(false);

	void createMaterial() noexcept(false);
	void createShape() noexcept(false);
	void createActor() noexcept(false);
};