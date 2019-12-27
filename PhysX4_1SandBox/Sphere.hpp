#pragma once

#include "Physics.hpp"

class Sphere final{
private:
	constexpr static float_t DEFAULT_STATIC_FRICTION_ = 0.0f;
	constexpr static float_t DEFAULT_DYNAMIC_FRICTION_ = 0.0f;
	constexpr static float_t DEFAULT_RESTITUTION_ = 0.6f;

	constexpr static float_t DEFAULT_RADIUS_ = 1.0f;
	constexpr static float_t DEFAULT_MASS_ = 1.0f;

public:
	Sphere() = delete;
	Sphere(const physx::PxTransform& transform, const float_t radius = DEFAULT_RADIUS_, const float_t mass = DEFAULT_MASS_) : transform_(transform), radius_(radius), mass_(mass), volume_(physx::PxPi * radius_ * radius_), density_(volume_ / mass){
		initialize();
	}
	Sphere(const Sphere&) = delete;
	Sphere(const Sphere&&) = delete;
	const Sphere& operator=(const Sphere&) = delete;
	const Sphere& operator=(const Sphere&&) = delete;
	~Sphere() noexcept = default;

private:
	const float_t radius_;

	const float_t			mass_;
	const float_t			volume_;
	const float_t			density_;

	physx::PxTransform		transform_;

	physx::PxMaterial* material_ = nullptr;
	physx::PxShape* shape_ = nullptr;
	physx::PxRigidDynamic* actor_ = nullptr;

public:
	physx::PxRigidDynamic& getActor() noexcept{
		return(*actor_);
	}

private:
	const bool initialize() noexcept(false);

	const bool createMaterial() noexcept(false);
	const bool createShape() noexcept(false);
	const bool createActor(const physx::PxU32 pos_it, physx::PxU32 velo_it) noexcept(false);
};