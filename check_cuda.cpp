#include <cstdio>
#include <cuda_runtime.h>

#define RC_OK       0
#define RC_WARNING  1
#define RC_CRITICAL 2
#define RC_UNKNOWN  3

int main() {
  int deviceCount;
  cudaDeviceProp deviceProp;
  
  cudaGetDeviceCount(&deviceCount);

  if (deviceCount == 0) {
    printf("CRITICAL: No GPUs detected\n");
    return(RC_CRITICAL);
  } else if (deviceCount == 1) {
    cudaGetDeviceProperties(&deviceProp, 0);
    printf("OK: %s (compute capability %d.%d)\n",
           deviceProp.name, deviceProp.major, deviceProp.minor);
    return(RC_OK);
  } else {
    printf("OK: %d GPUs found\n", deviceCount);
    
    int device;
    for (device = 0; device < deviceCount; ++device) {
      cudaGetDeviceProperties(&deviceProp, device);
      printf("%d: %s (compute capability %d.%d)\n", device, deviceProp.name, deviceProp.major, deviceProp.minor);
    }
    return(RC_OK);
  }
}
