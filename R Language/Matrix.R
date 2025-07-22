matrix1 <- matrix(1:9, nrow = 3, ncol = 3)
matrix2 <- matrix(9:1, nrow = 3, ncol = 3)

cat("Matrix 1:\n")
print(matrix1)
cat("Matrix 2:\n")
print(matrix2)

cat("\nOperations: \n")

cat("\nAddition: \n")
addition <- matrix1 + matrix2
print(addition)

cat("\nSubtraction: \n")
subtraction <- matrix1 - matrix2
print(subtraction)

cat("\nMultiplication: \n")
multiplication <- matrix1 %*% matrix2
print(multiplication)

cat("\nTranspose of Matrix 1: \n")
transpose1 <- t(matrix1)
print(transpose1)

cat("\nTranspose of Matrix 2: \n")
transpose2 <- t(matrix2)
print(transpose2)
