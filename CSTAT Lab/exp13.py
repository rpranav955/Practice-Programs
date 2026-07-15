import matplotlib.pyplot as plt
import numpy as np


x = np.linspace(-10, 10, 100)


y = x


plt.figure(figsize=(8, 6))
plt.plot(x, y, label='$f(x) = x$')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(True, linestyle='--', alpha=0.7)
plt.xlabel('$x$')
plt.ylabel('$f(x)$')
plt.title('Plot of $f(x) = x$')
plt.legend()


plt.show()
