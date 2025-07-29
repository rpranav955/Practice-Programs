data <- data.frame(
  Name = c("Amiya", "Raj", "Asish"),
  Language = c("R", "Python", "Java"),
  Age = c(22, 25, 45)
)

cat("Original Dataframe:\n")
print(data)

new_row <- data.frame(Name = "Nitin", Language = "C++", Age = 30)
data <- rbind(data, new_row)

cat("\nDataframe after adding a new row:\n")
print(data)

data <- data[-3,]

cat("\nDataframe after removing a row:\n")
print(data)

cat("\nSummary of the dataframe:\n")
print(summary_data)