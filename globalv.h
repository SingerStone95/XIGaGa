#pragma once
extern int g_int; // 仅仅是声明，可以被无限依赖
// extern int g_int = 10 这么写，就表示声明+定义，如果被依赖多次就会导致重复定义