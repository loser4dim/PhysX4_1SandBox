#pragma once

#include "PhysicsProperty.hpp"


class Scene final{
private:
	constexpr static float_t GRAVITY_ACCELERATION_ = -9.80665f;

public:
	Scene() = delete;
	Scene(const physx::PxReal frequency) noexcept(false) : simulaton_frequency_(frequency), property_(GRAVITY_ACCELERATION_){
	}
	Scene(const Scene&) = delete;
	Scene(const Scene&&) = delete;
	const Scene operator=(const Scene&) = delete;
	const Scene operator=(const Scene&&) = delete;
	~Scene() noexcept = default;

private:
	const physx::PxReal simulaton_frequency_;
	PhysicsProperty property_;

public:
	bool simulateStep() noexcept(false);

	void addStaticActor(physx::PxRigidStatic& actor) noexcept(false);
	void addDynamicActor(physx::PxRigidDynamic& actor) noexcept(false);
};