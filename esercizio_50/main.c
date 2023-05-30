#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
return_literal (int code)
{
    switch (code)
    {
        case 100:
            return "Boston Processing Center";
        break;

        case 200:
            return "Denver Processing Center";
        break;

        case 300:
            return "Atlanta Processing Center";
        break;

        case 400:
            return "San Jose Processing Center";
        break;

        default:
            return "Unknown code";
        break;
    }
}

char *
return_static_literal (int code, int subcode)
{
    static char bpcenter[] = "Boston Processing Center";
    static char dpcenter[] = "Denver Processing Center";
    static char apcenter[] = "Atlanta Processing Center";
    static char sjpcenter[] = "San Jose Processing Center";

    switch (code)
    {
        case 100:
            return bpcenter;
        break;

        case 135:
            if (subcode < 35)
            {
                return dpcenter;
            }
            else
            {
                return bpcenter;
            }
        break;

        case 200:
            return dpcenter;
        break;

        case 300:
            return apcenter;
        break;

        case 400:
            return sjpcenter;
        break;

        default:
            return "Unknown code";
        break;
    }
}

int
main (int argc, char ** argv)
{
    printf("%s\n", return_literal(100));

    printf("%s\n", return_static_literal(135, 5));

	return (0);
}	/* main() */