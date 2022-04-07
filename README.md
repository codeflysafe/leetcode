# leetcode
Solution for leetcode

## 使用方式

增加`include`文件，修改`include`下的`leetcode.h`文件

### shell 脚本执行
执行 ./run.sh 200(问题编号)

```shell
(base) ➜  leetcode git:(main) ./run.sh 215          
run ./leetcode/215_kth_largest_element_in_an_array.cpp
5
./leetcode/215_kth_largest_element_in_an_array.cpp end
(base) ➜  leetcode git:(main) ✗ 

```

```bash
#!/bin/bash

files=`find ./leetcode -name "$1*.cpp"`
#echo "files are $files"

for file in ${files[*]}
do
  echo "run $file";
  echo `g++ -std=c++11 -I ./include $file -o lc.o && ./lc.o`
  echo "$file end"
  rm -rf ./lc.o
done
```

### 手动`cmake`编译执行
```cmake
add_executable(leetcode leetcode/310_minimum_height_trees.cpp)
```
将其中的`leetcode/310_minimum_height_trees.cpp` 替换为要是执行的cpp文件

### 执行环境
- maxOS Big Sur 
- linux