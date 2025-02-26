import numpy as np

# Fungsi untuk menerapkan metode Gauss-Seidel
def gauss_seidel(A, b, x0, tol=1e-10, max_iter=1000):
    n = len(b)
    x = np.copy(x0)
    
    for k in range(max_iter):
        x_new = np.copy(x)  # Salin nilai x sebelumnya
        
        # Iterasi untuk setiap persamaan
        for i in range(n):
            # Jumlahkan komponen di sisi kanan persamaan
            sum_ = b[i]
            for j in range(n):
                if j != i:
                    sum_ -= A[i][j] * x_new[j]
            
            # Hitung nilai variabel yang baru
            x_new[i] = sum_ / A[i][i]
        
        # Periksa apakah konvergen (norma perubahan sangat kecil)
        if np.linalg.norm(x_new - x, ord=np.inf) < tol:
            print(f"Konvergen setelah {k+1} iterasi.")
            return np.round(x_new).astype(int)  # Mengonversi hasil ke integer
        
        # Perbarui solusi untuk iterasi berikutnya
        x = np.copy(x_new)
    
    print("Mencapai jumlah iterasi maksimum.")
    return np.round(x).astype(int)  # Mengonversi hasil ke integer

# Koefisien matriks A dan vektor b
A = np.array([[4, 1, -1],
              [1, 3, 2],
              [3, 1, 2]])

b = np.array([3, 7, 6])

# Tebakan awal
x0 = np.array([0, 0, 0])

# Menyelesaikan sistem persamaan menggunakan Gauss-Seidel
result = gauss_seidel(A, b, x0)
import numpy as np

# Fungsi untuk menerapkan metode Gauss-Seidel
def gauss_seidel(A, b, x0, tol=1e-10, max_iter=1000):
    n = len(b)
    x = np.copy(x0)
    
    for k in range(max_iter):
        x_new = np.copy(x)  # Salin nilai x sebelumnya
        
        # Iterasi untuk setiap persamaan
        for i in range(n):
            # Jumlahkan komponen di sisi kanan persamaan
            sum_ = b[i]
            for j in range(n):
                if j != i:
                    sum_ -= A[i][j] * x_new[j]
            
            # Hitung nilai variabel yang baru
            x_new[i] = sum_ / A[i][i]
        
        # Periksa apakah konvergen (norma perubahan sangat kecil)
        if np.linalg.norm(x_new - x, ord=np.inf) < tol:
            print(f"Konvergen setelah {k+1} iterasi.")
            return np.round(x_new).astype(float)  # Mengonversi hasil ke integer
        
        # Perbarui solusi untuk iterasi berikutnya
        x = np.copy(x_new)
    
    print("Mencapai jumlah iterasi maksimum.")
    return np.round(x).astype(float)  # Mengonversi hasil ke integer

# Koefisien matriks A dan vektor b
A = np.array([[4, 1, -1], 
              [1, 3, 2],
              [3, 1, 2]], dtype=float) #trailing coma 

b = np.array([3, 7, 6],dtype=float)

# Tebakan awal
x0 = np.array([0, 0, 0],dtype=float)

# Menyelesaikan sistem persamaan menggunakan Gauss-Seidel
result = gauss_seidel(A, b, x0)

print("Solusi:", result)
