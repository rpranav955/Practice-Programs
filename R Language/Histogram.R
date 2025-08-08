height <- c(rep(136,4),rep(141,12),rep(146,16),rep(151,8))

breaks <- c(135,140,145,150,155)

hist(height,
     breaks=breaks,
     main="Height of students",
     xlab="Height(m)",
     ylab="No.of students",
     col="#F4A582")
