import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d
from scipy.linalg import norm
from scipy.fft import fft, ifft
from scipy.stats import bernoulli

# No. of Pilots: 4
# Cyclic Extension: 25%(16)
np.random.seed(0)

# Generating and coding data
t_data = np.random.randint(0, 2, size=(9600,)).astype(float)

x = 1
# Size of cycle prefix extension
n_cpe = 16
Nfft = 64
n_taps = 3
with_cp = 80
symbol_number = 80

# Channel Transfer Function
g = np.exp(-(np.arange(n_taps)))

g = g / norm(g)

cons_sym_id = np.zeros((2, symbol_number))
x_cpe = np.zeros((Nfft + n_cpe, symbol_number), dtype=np.complex128)

for d in range(symbol_number):
    data = t_data[x-1:x+119]
    x += 120

    k = 3
    n = 6
    s1 = data.size


    # Binary stream to symbols
    cons_data = data.reshape(int(s1 / 2), 2)
    cons_sym_id[:, d] = np.packbits(cons_data, axis=1).flatten()

    # Symbol modulation
    mod_data = np.mod(cons_sym_id[:, d], 4)

    # Pilot insertion
    pilt = 1 + 1j
    mod_data = np.concatenate(([pilt], mod_data[0:15], [pilt], mod_data[15:30],
                               [pilt], mod_data[30:45], [pilt], mod_data[45:60]))

    # IFFT and CP adding
    x_ifft = ifft(mod_data)
    x_cpe[:, d] = np.concatenate((x_ifft[-n_cpe:], x_ifft))

    
barker = np.array([1, 1, 1, -1, -1, 1, -1])
seq = np.tile(barker, int(with_cp / len(barker)))

x_cpe = np.column_stack((seq, seq, x_cpe[:, 0:40], seq, x_cpe[:, 40:80]))
x_transmitted = x_cpe.flatten()
print(x_transmitted)