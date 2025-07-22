sum_of_digits_while <- function(number){
  sum <- 0
  while (number > 0){
    digit <- number %% 10
    sum <- sum + digit
    number <- number %/% 10
  }
  return(sum)
}

num <- as.integer(readline("Enter your number: "))
result <- sum_of_digits_while(num)

print(paste("Sum of digits using while loop: ", result))
