#include "browser.h"

int main(int argc, char **argv)
{
	Browser browser(&argc, argv);
	browser.run();

	return 0;
}