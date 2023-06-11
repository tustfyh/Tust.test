#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void replace(char str[], char old_char, char new_char)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == old_char)
        {
            str[i] = new_char;
        }
    }
}

bool all_letters(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[100];
    char old_char, new_char;

    // 输入字符串
    while (true)
    {
        printf("请输入一个字符串: ");
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = '\0';

        if (all_letters(str))
        {
            break;
        }
        else
        {
            printf("错误：请输入字母！\n");
        }
    }

    // 输入第一个字符
    while (1)
    {
        printf("请输入第一个字符: ");
        old_char = getchar();

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (isalpha(old_char))
        {
            break;
        }
        else
        {
            printf("错误：请输入字母！\n");
        }
    }

    // 输入第二个字符
    while (1)
    {
        printf("请输入第二个字符: ");
        new_char = getchar();

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (isalpha(new_char))
        {
            break;
        }
        else
        {
            printf("错误：请输入字母！\n");
        }
    }
    replace(str, old_char, new_char);
    printf("替换后的字符串: %s\n", str);

    return 0;
}
