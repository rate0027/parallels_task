
並列分散処理:グループ学習
===

複数の言語で並列処理を行い特性を把握する？

##Description
目標:ソートを並列化する  
同じソートを別の方法で並列化して速度を図る.  


##Usage
作ったプログラムの使い方とか  

countsort:  
```
mpicc countsort.c
mpirun -np num a.out
```

##etc
要望とかその他もろもろ,

参考サイト:  
- 分布数え上げソート(countsort)のアルゴリズム  
http://www.codereading.com/algo_and_ds/algo/counting_sort.html

- 並列プログラムサンプル置き場  
https://computing.llnl.gov/tutorials/mpi/exercise.html



