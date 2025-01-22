/**
 * ft_strspn : 
 * strspn 函数计算一个字符串（s）的 初始段 的长度，该段仅由另一个字符串（accept）中的字符组成。
 * 
 * @note
 * - First While (s[i]) (longer str)
 * - Secondly while (accept[j]) (reference str(shorter))
 * - If found matching character -> break
 * - Return (i) -> The length of accepted str
 */
#include <unistd.h>
size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int j;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				break ;// Found a match, break the inner loop
			j++;
		}
		if (accept[j] == '\0')
			break ; // No match found, break the outer loop
		i++;
	}
	return (i);// Return the length of the span
}
#include <stdio.h>
int main() 
{
    const char *str = "hello world!";
    const char *accept = "helo "; // Characters to accept
    size_t span_length = ft_strspn(str, accept);

	printf("The length of the initial segment of \"%s\"\nThat consists only of characters in \"%s\" is: %zu\n",
           str, accept, span_length);

    return 0;
}

/*
In the string "hello world!", 
the characters that are found in the string "helo " are:

'h', 'e', 'l', 'l', 'o' (these characters are present in accept).


The first character that is not found in accept is a space (' '), 
and hence the length of the initial segment is 5.

*/
/*
Sure! Here’s the translation of the explanation into Chinese:

### `strspn` 的功能

`strspn` 函数计算一个字符串（`s`）的 **初始段** 的长度，该段仅由另一个字符串（`accept`）中的字符组成。

### 细分说明
1. **输入字符串**：
   - **s**：你想检查的主字符串。
   - **accept**：你希望允许的字符字符串。

2. **工作原理**：
   - 从字符串 `s` 的开头开始。
   - 一个一个地检查每个字符。
   - 如果 `s` 中的字符在 `accept` 中找到，它会继续检查下一个字符。
   - 如果发现 `s` 中的字符 **不** 在 `accept` 中，它会停止检查。

3. **输出**：
   - 返回从 `s` 的开始到第一个未找到的字符之间的字符数。

### 示例
例如，如果你有：
- `s = "hello world!"`
- `accept = "helo "`

这个函数将检查：
- 'h'（在 `accept` 中找到）
- 'e'（在 `accept` 中找到）
- 'l'（在 `accept` 中找到）
- 'l'（在 `accept` 中找到）
- 'o'（在 `accept` 中找到）

然后它到达一个空格（' '）（也在 `accept` 中找到），并继续检查直到遇到 'w'（不在 `accept` 中）。

因此，`strspn` 将返回 `5`，因为 `s` 的前 **五个** 字符都在 `accept` 中找到。

### 总结
`strspn` 告诉你从一个字符串的开头开始，有多少个字符仅由另一个字符串中的特定允许字符构成。


*/