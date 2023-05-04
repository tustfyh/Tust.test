#include <stdio.h>

int main()
{
    int m, n;
    printf("请输入两个整数: ");
    scanf_s("%d %d", &m, &n);

    int sum = 0;
    int min = m < n ? m : n;

    for (int i = 1; i <= min; i++) {
        if (m % i == 0 && n % i == 0)
            sum += i;
    }

    printf("%d 和 %d 的公约数之和为: %d\n", m, n, sum);

    return 0;
}