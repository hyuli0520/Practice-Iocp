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
#define Xalloc(size) PoolAllocator::Alloc(size)
#define Xrelease(ptr) PoolAllocator::Release(ptr)
#else
#define xalloc(size) BaseAllocator::Alloc(size)
#define xrelease(ptr) BaseAllocator::Release(ptr)
#endif

/*---------------
	  Crash
---------------*/

#define CRASH(cause)						\
{											\
	uint32* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

#define ASSERT_CRASH(expr)			\
{									\
	if (!(expr))					\
	{								\
		CRASH("ASSERT_CRASH");		\
		__analysis_assume(expr);	\
	}								\
}