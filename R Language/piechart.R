grades <- c(A=20, B=30, C=25, D=15, F=10)

colors <- c("#1f77b4","#ff7f0e", "#2ca02c", "#d62728", "#9467bd")

pie(grades, labels = paste(names(grades), "(", grades, "%)", sep =""),col = colors, main = "Percentage of Grades in class")