#pragma once

#include "Physics.hpp"
#include <thread>

enum class FilterShader{
	DEFAULT_ = 0,
	CONTACT_REPORT_ = 1,
	CUSTOM = 2,
	REBOT_CONTACT_REPORT = 3
};

class PhysicsProperty final{
private:
	constexpr static const char* const LOCAL_HOST_NAME_ = "127.0.0.1";
	constexpr static int PORT_NUM_ = 5425;
	constexpr static unsigned int TIME_OUT_ = 10;

public:
	PhysicsProperty() = delete;
	PhysicsProperty(const float_t gravity) noexcept(false){
		initialize(gravity);
	}
	PhysicsProperty(const PhysicsProperty&) = delete;
	PhysicsProperty(const PhysicsProperty&&) = delete;
	const PhysicsProperty& operator=(const PhysicsProperty&) = delete;
	const PhysicsProperty&& operator=(const PhysicsProperty&&) = delete;
	~PhysicsProperty() noexcept = default;

public:
	physx::PxScene* scene_ = nullptr;

private:
	const physx::PxU32 thread_num_ = std::thread::hardware_concurrency() - 1;

	physx::PxDefaultAllocator allocator_;
	physx::PxDefaultErrorCallback error_callback_;
	physx::PxFoundation* foundation_ = nullptr;
	physx::PxPvd* pvd_ = nullptr;
	physx::PxPhysics* physics_ = nullptr;
	physx::PxDefaultCpuDispatcher* dispatcher_ = nullptr;

	physx::PxCooking* cooking_ = nullptr;
	FilterShader filter_sgader_ = FilterShader::CUSTOM;

public:
	const bool simulateStep(physx::PxReal time) noexcept(false);

private:
	const bool initialize(const float_t gravity) noexcept(false);

	const bool createFoundation() noexcept(false);
	const bool createPVD() noexcept(false);
	const bool createPhysics() noexcept(false);

	const bool createCooking() noexcept(false);

	const bool createDispacher() noexcept(false);
	const bool createScene(const float_t gravity) noexcept(false);
	const bool createPVDClient() noexcept(false);
};