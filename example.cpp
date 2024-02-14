#include <iostream>
#include "atk/toolkit.h"

using namespace atk;
using namespace glm;

int main(int argc, char** argv)
{
   Skeleton skeleton;
   Motion motion;

   BVHReader reader;
   reader.load("../samba_dancing.bvh", skeleton, motion);

   // How many frames (aka keys)?
   int numFrames = motion.getNumKeys();  
   std::cout << "The number of frames is " << numFrames << std::endl;

   // What is the framerate?
   float fps = motion.getFramerate();
   std::cout << "The frame rate is " << fps << std::endl;

   // What is the duration?
   float duration = motion.getDuration();
   std::cout << "The duration of the animation is " << duration << std::endl;

   // Print out local rotations as a quaternion for frame 0
   for (int i = 0; i < (int) frame0.jointRots.size(); i++)
   {
      glm::quat q = frame0.jointRots[i];
      Joint* joint = skeleton.getByID(i);
      printf("Joint %d (%s): %.2f %.2f %.2f %.2f\n", i, joint->getName().c_str(), 
        q.x, q.y, q.z, q.w);
   }
}
