#pragma once

/*---------------
	  Lock
---------------*/

#define USE_MANY_LOCKS(count)	Mutex _locks[count];
#define USE_LOCK				USE_MANY_LOCKS(1)
#define	WRITE_LOCK_IDX(idx)		LockGuard writeLockGuard_##idx(_locks[idx]);
#define WRITE_LOCK				WRITE_LOCK_IDX(0)

/*--------------
	Memory
--------------*/

#ifdef _DEBUG
#define xalloc(size) BaseAllocator::Alloc(size)
#define xrelease(ptr) BaseAllocator::Release(ptr)
#else
#define xalloc(size) BaseAllocator::Alloc(size)
#define xrelease(ptr) BaseAllocator::Release(ptr)
#endif