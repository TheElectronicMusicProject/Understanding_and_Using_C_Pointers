#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int
main (void)
{
    char stringa[] = "Nihongo";
    wchar_t stringa_strana[] = L"Ciao";
    const char * const tab_header = "Sound";

    setlocale(LC_ALL, "");

    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof('a'));
    printf("%d\n", sizeof(wchar_t));

    printf("%s\n", stringa);
    printf("%ls\n", stringa_strana);

    printf("%s\n", tab_header);
    tab_header = 'L';
    printf("%s\n", tab_header);

	return (0);
}	/* main() */