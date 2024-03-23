import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

# Charger les données depuis le fichier output.log
with open('output.log', 'r') as file:
    # Lire toutes les lignes du fichier
    lines = file.readlines()

# Initialiser des listes pour stocker les valeurs de temps, Ra et Rb
Ra_xvalues = []
Ra_yvalues = []

Rb_xvalues = []
Rb_yvalues = []

# Parcourir chaque ligne du fichier et extraire les valeurs
for line in lines[1:]:  # Commencer à partir de la deuxième ligne pour ignorer les en-têtes
    # Diviser la ligne en colonnes en utilisant l'espace comme séparateur
    columns = line.split()

    # Assurez-vous que la ligne a suffisamment de colonnes
    if len(columns) >= 10:
        Rax = float(columns[5])
        Ray = float(columns[6])

        Rbx = float(columns[7])
        Rby = float(columns[8])

        Ra_xvalues.append(Rax)
        Ra_yvalues.append(Ray)
        Rb_xvalues.append(Rbx)
        Rb_yvalues.append(Rby)

Ra_xvalues = np.array(Ra_xvalues)
Rb_xvalues = np.array(Rb_xvalues)

Ra_yvalues = np.array(Ra_yvalues)
Rb_yvalues = np.array(Rb_yvalues)

# Initialiser la figure en 2D
fig, ax = plt.subplots()
ax.set_xlim([-0.01, 0.01])
ax.set_ylim([-0.01, 0.01])
ax.set_xlabel('X')
ax.set_ylabel('Y')

# Ajouter les points initiaux des particules
point1, = ax.plot([], [], 'go', label='centre de masse A', markersize=100)
point2, = ax.plot([], [], 'bo', label='centre de masse B', markersize=100)

# Trajectoires des particules
# line1, = ax.plot([], [], 'g-', label='Ra Trajectory')
# line2, = ax.plot([], [], 'b-', label='Rb Trajectory')

def init():
    point1.set_data(Ra_xvalues[0], Ra_yvalues[0])
    point2.set_data(Rb_xvalues[0], Rb_yvalues[0])
    # line1.set_data([], [])
    # line2.set_data([], [])
    return point1, point2,

def update(frame):
    point1.set_data(Ra_xvalues[frame], Ra_yvalues[frame])
    point2.set_data(Rb_xvalues[frame], Rb_yvalues[frame])
    # line1.set_data(Ra_xvalues[:frame], Ra_yvalues[:frame])
    # line2.set_data(Rb_xvalues[:frame], Rb_yvalues[:frame])
    return point1, point2,

# Créer l'animation
animation = FuncAnimation(fig, update, frames=len(Ra_xvalues), init_func=init, blit=True, interval=10)

# Afficher l'animation
plt.title('Animation des centres de masses des nanoparticules')
# plt.legend()

plt.show()
