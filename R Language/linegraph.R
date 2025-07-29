subjects <- c(1,2,3,4,5)

student1_marks <- c(70,80,89,90,95)
student2_marks <- c(60,75,80,85,90)

plot(subjects, student1_marks, type = "o", col = "darkblue", xlab = "Subjects", ylab = "Marks", ylim = c(0,100), main = "Marks of Two Students")
lines(subjects, student2_marks, type = "o", col = "darkgreen")