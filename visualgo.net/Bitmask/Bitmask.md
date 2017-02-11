# 1. Set bit
```c
// 功能：将‘value’的二进制数的第‘bit+1’位置置为1
// 思想：使用 按位或（|）
int SetBit(int value, int bit)
{
	return value | (1 << bit);
}
```
# 2. Check bit
```c
// 功能：检查‘value’的二进制数的第‘bit+1’位置是否为 0
// 思想：使用 按位与（&）
void CheckBit(int value, int bit)
{
	int result = value & (1 << bit);
	if (!result) // result == 0
	{
		printf("第 %d 位为 0\n", bit);
	}
	else // result 非0
	{
		printf("第 %d 位为 1\n", bit);
	}
}
```

# 3. Toggle bit
```c
// 功能：将‘value’的二进制数的第‘bit+1’位置的数取反
// 思想：使用 异或（^）
int ToggleBit(int value, int bit)
{
	int result = value ^ (1 << bit);
	return result;
}
```
# 4. Clear bit
```c
// 功能：将‘value’的二进制数的第‘bit+1’位置的数置为 0
// 思想：使用 按位取反（~） + 按位与
int ClearBit(int value, int bit)
{
	int temp1 = 1 << bit; // 将 1 按位左移 bit 个位置
	int temp2 = ~temp1;   // 按位取反
	int result = value & temp2; // 按位与
  	// result = value & ( ~( 1 << bit ) )

	return result;
}
```

# 5. least significant bit
```c
// 功能：‘最低有效位’ least significant bit
// 即将‘value’的二进制数的最右边的1保留，其余的位置全部置为 0
// 效果：11001000 -> 00001000
// 思想：使用 按位取反 + 按位与
int LeastBit(int value)
{
	int temp1 = ~value;
	int temp2 = temp1 + 1;
	int result = value & temp2;
	//result = value & ( ( ~value ) + 1 );
	return result;
}
```