#ifndef structure
#define structure

struct source
{
    char* sourcePath;
    struct source* nextSource;
};

struct head
{
	struct source* sourceTarget;
};

#endif
