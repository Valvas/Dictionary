#ifndef structure
#define structure

struct source
{
    char* sourcePath;
    struct source* nextSource;
};

struct word
{
	char* title;
	struct word* nextWord;
};

struct head
{
	struct source* sourceTarget;
};

struct primary
{
	struct word* wordTarget;
};

#endif
