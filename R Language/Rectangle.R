# Calculate area and perimeter of a rectangle

calculateArea <- function(length, width){
  area <- length * width
  return(area)
}
calculatePerimeter <- function(length, width){
  perimeter <- 2*(length + width)
  return(perimeter)
}

length <- as.numeric(readline("Enter Length: "))
width <- as.numeric(readline("Enter Width: "))

cat("Area: ", calculateArea(length, width), "\n")
cat("Perimeter: ", calculatePerimeter(length, width), "\n")
