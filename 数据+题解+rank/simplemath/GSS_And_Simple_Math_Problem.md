**GSS and Simple Math Problem**

Given $n$ positive integers $a_1, a_2, \ldots a_n$, your task is to calculate the product of these integers. The answer is less than $10^{10^5}$.

哈夫曼编码顺序的NTT/FFT。

这题的题面非常简单，数据也没有任何坑。数据范围一眼就能让人想到FFT/NTT，但是如果直接写FFT或者NTT会得到TLE，比如一组有10^5个10的数据，可以证明它的复杂度是$n^2\log n$. 作为参考，朴素做法面对这个数据是$n^2$的。这是这一题的极端数据。

如果我们顺着乘起来，会发现第$i$次FFT的大小最小是$i$，取FFT大小之和作为时间复杂度的参考，则总复杂度是$\sum i\log i$，大约是$n^2 \log n$这个级别。

下面我们考虑使用贪心做法，每次取两个FFT大小最小的数相乘，可以证明，如果一个数被乘了两次，那么第二次乘完之后的FFT大小不小于它第一次被乘之前的FFT大小的两倍，证明如下：取长度分别为$a, b, c$的三个数，$a$先和$b$乘，乘完之后再和$c$乘。显然有$a, b \le c$就发现$b + c \ge a$，则$a + b + c \ge 2a$

通过这个结论，可以知道，如果总长度为$n$，那么每层子树的权值和也应当$\le n$，总层数不大于$2\log n$层，每一节点的复杂度为$O(n \log n)$，可以计算得到总复杂度是$O(n \log^2 n)$

这一题的做法是在CCPC 2017杭州赛区上想出来的，原题正解用多项式逆元来做，有个直接上FFT的naive做法，但是会TLE，于是我想出来了类似的做法，为了节约内存导致常数非常大，考虑到FFT相关的题目常数都不小，所以也不必在意。

实在想不出合适的背景，就只能出这样直白的题目，对于因为难度估计错误或者是被标题误导而耽误时间的队伍我只能说抱歉。