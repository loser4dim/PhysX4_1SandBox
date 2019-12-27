#pragma once

#ifndef _DEBUG
	#define NDEBUG
#endif

#include <PxPhysicsAPI.h>
#include <PxPhysics.h>
#include <PxRigidStatic.h>
#include <PxRigidDynamic.h>
#include <PxSceneDesc.h>
#include <PxSimulationEventCallback.h>
#include <extensions/PxExtensionsAPI.h>
#include <extensions/PxDefaultErrorCallback.h>
#include <extensions/PxDefaultAllocator.h>
#include <extensions/PxDefaultSimulationFilterShader.h>
#include <extensions/PxDefaultCpuDispatcher.h>
#include <extensions/PxShapeExt.h>
#include <extensions/PxSimpleFactory.h>

#include <extensions/PxCollectionExt.h>
#include <PxAggregate.h>

//#include <foundation/PxFoundation.h>
#include <foundation/PxMat44.h>
#include <cudamanager/PxCudaContextManager.h>

#pragma comment(lib, "PhysX_64")
#pragma comment(lib, "PhysXCommon_64")
#pragma comment(lib, "PhysXCooking_64")
#pragma comment(lib, "PhysXExtensions_static_64")
#pragma comment(lib, "PhysXFoundation_64")
#pragma comment(lib, "PhysXPvdSDK_static_64")

//constexpr size_t ARTICULATION_NUM_ = 128;