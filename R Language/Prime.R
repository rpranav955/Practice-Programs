isPrime <- function(num){
  if(num <= 1){
    return(FALSE)
  }
  for(i in 2:sqrt(num)){
    if(num %% i == 0){
      return(FALSE)
    }
  }
  return(TRUE)
}
cat("Prime numbers upto 1000 are: \n")
for(i in 2:1000){
  if(isPrime(i)){
    cat(i, " ")
  }
}
