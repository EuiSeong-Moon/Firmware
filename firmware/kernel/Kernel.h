#ifndef KERNEL_KERENL_H_
#define KERNEL_KERNEL_H_

#include "task.h"
#include "event.h"

void Kernel_yield (void);
void Kernel_start (void);

#endif