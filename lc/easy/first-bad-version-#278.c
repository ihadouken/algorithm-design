/* Given the total number versions of a project, output the first bad version
 * of the project. If a version is indeed bad, then all subsequent versions
 * are also bad. A particular version can be checked using an API function. */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isBadVersion(int ver, int ans);
int firstBadVersion(int n, int ans);

int main(void) {
    int n = 5;
    int ans = 4;
    printf("I: n = %d, bad = %d\n", n, ans);
    printf("O: %d\n", firstBadVersion(n, ans));
    return 0;
}

int isBadVersion(int ver, int ans) {
    if (ver >= ans)
        return TRUE;
    else
        return FALSE;
}

int firstBadVersion(int n, int ans) {
    int l, r, m;
    l = 1;
    r = n;

    while (l < r) {
        m = l + (r-l) / 2;
        if (isBadVersion(m, ans))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

