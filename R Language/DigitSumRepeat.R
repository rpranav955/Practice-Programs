sum_of_digits_repeat <- function(number){
  sum <- 0
  repeat {
    digit <- number %% 10
    sum <- sum + digit
    number <- number %/% 10
    
    if(number == 0){
      break
    }
  }
  return(sum)
}

num <- as.integer(readline("Enter your number: "))
result <- sum_of_digits_while(num)

print(paste("Sum of digits using while loop: ", result))
