#include "Scene.hpp"
#include "Ground.hpp"

#ifdef _DEBUG
	#include "Sphere.hpp"
#endif

#include <iostream>

using namespace std;
using namespace physx;

int main(int argc, char** argv){
#ifdef _DEBUG
	for(int i(0); i < argc; ++i){
		cout << argv[i] << endl;
	}
#endif

	constexpr PxReal DEFAULT_FREQUENCY = 60.0f;
	Scene simulation_scene(DEFAULT_FREQUENCY);

	const PxTransform ground_transform = PxTransform(0.0f, 0.0f, 0.0f, PxQuat(PxPiDivTwo, PxVec3(0.0f, 0.0f, 1.0f)));
	Ground simulation_ground(ground_transform);
	simulation_scene.addStaticActor(simulation_ground.getActor());

#ifdef _DEBUG
	const PxTransform sphere_transform = PxTransform(0.0f, 20.0f, 0.0f, PxQuat(0.0f, PxVec3(0.0f, 1.0f, 0.0f)));
	Sphere sphere(sphere_transform);
	simulation_scene.addDynamicActor(sphere.getActor());
#endif

	constexpr size_t frame_num = 1000;
	
	for(size_t i(0); i < frame_num; ++i){
		simulation_scene.simulateStep();
#ifdef _DEBUG
		if(i == 0){
			physx::PxRigidBody& body = sphere.getActor();
			body.addForce(physx::PxVec3(1000.0f, 0.0f, 0.0f));
		}
#endif
	}

#ifdef _WIN64
	system("pause");
#endif

	return(EXIT_SUCCESS);
}