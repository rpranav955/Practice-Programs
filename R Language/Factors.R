find_factors <- function(num){
  factors <- c()
  for (i in 1:num){
    if (num %% i== 0){
      factors <- c(factors, i)
    }
  }
  return(factors)
}

  number <- as.integer(readline("Enter your number: "))
  factors <- find_factors(number)
  
  cat("The factors of ", number, "are: ", factors, "\n")
