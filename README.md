# Advanced Programming - HW2
<p  align="center"> <b>Homework 3 - Spring 2023 Semester <br> Deadline: Monday Farvardin 14st - 11:59 pm</b> </p>

## Outline
In this homework we are going to implement **Matrix** library that represents a mathematical matrix.

For storing matrix data use `int** matrix`. Next, we want to add row(s) or column(s) to the matrix. For the optimality of this issue use `rowCapacity` and `colCapacity`that return the size of the storage space currently allocated for the rows and columns. These capacities are not necessarily equal to the `rowSize` and `colSize`. They can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion. The first time when the matrix was created with zero rows and columns, capacity equals 0. When `rowSize` became 3, `rowCapacity` must be 4, and when `rowSize` became 5, `rowCapacity` must be 8, and when and so on. This algorithm is correct for `colCapacity'.

## Functions

### Constructors
- **default constructor**: create matrix with 0 rows and columns(size).
```cpp
Matrix();
```
- **constructor with one parameter**: parameter is the size of rows and columns. Data of matrix equals 0.
```cpp
Matrix(int size);
```
- **constructor with two parameters**: first parameter is row size and second is column size. Data of matrix equals 0.
```cpp
Matrix(int row, int column);
```
- **constructor with initializer_list**
```cpp
Matrix(std::initializer_list<std::initializer_list<int>> a)
```
- **copy constructor**
``` cpp
Matrix(const Matrix& m);
```

### member functions
- **append** : append two matrices to each other with given axis(0 for horizontally append and 1 for vertically append, default: 0) and save it.
```cpp
const Matrix& append(const Matrix& m, axis=0);
```
- **display** : display matrix.
```cpp
void display() const;
```
### operators
- **operator***: product matrices and return it by reference.
- **operator+**: return sum of matrices and return it by reference.
- **operator+=**: return sum of matrices and save it and return by reference.
- **operator-**: return subtract of matrices and return it by reference.
- **operator|**: solve `Ax = b` with `A | b` with less than 0.001 precision and return `x` in matrix format.
- **operator++**: add 1 to each data in matrix.(implement post-increment and pre-increment).
- **operator--**: subtract 1 from each data in matrix.(implement post-decrement and pre-decrement).
- **operator[]**: return data in row given row.(we can use `matrix[0][0]`).
- **operator<<**: print matrix.
- **operator==**: check equality of two matrix. first check size and next check data by its indexes.
- **operator<=>**: first check `rowSize`, next `colSize` and next sum of data in matrix.
- **operator=**: copy all data of right matrix on left matrix.

# Finally
- don't change `main.cpp`.
- write Makefile to run your code.
- keep all your implementations in `matrix.cpp` and `matrix.h.` do not alter other files at all. In case you want to test your code you may only use the `debug` section of the `main.cpp`
```cpp
if (true) // make false to run unit tests  
{
    // debug section 
}
else {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << RUN_ALL_TESTS() << std::endl;
}
```
<br>

<h2 align=center> GOOD LUCK </h2>