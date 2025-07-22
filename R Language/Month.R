month_number <- as.integer(readline("Enter a month number (1-12): "))

month_name <- switch(month_number,
                     "January",
                     "February",
                     "March",
                     "April",
                     "May",
                     "June",
                     "July",
                     "August",
                     "September",
                     "October",
                     "November",
                     "December",
                     "Invalid Number")

cat("The month corresponding to ", month_number,"is: ",month_name,"\n")
