import matplotlib.pyplot as plt

# Les valeurs de numOperations que vous avez testées
numOperationsValues = [1e7, 1e8, 1e9, 2e9]

# Les temps d'exécution correspondants que vous avez collectés
executionTimes_add_float = [0, 0, 302, 603]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_add_int = [0, 0, 302, 605]

executionTimes_mult_float = [0, 0, 302, 608]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_mult_int = [0, 29, 303, 603]

executionTimes_div_float = [0, 34, 307, 609]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_div_int = [0, 30, 303, 609]


# Tracer le graphique
plt.plot(numOperationsValues, executionTimes_add_float, marker='o', label='add_float')
plt.plot(numOperationsValues, executionTimes_add_int, marker='o', label='add_int')

plt.plot(numOperationsValues, executionTimes_mult_float, marker='o', label='mult_float')
plt.plot(numOperationsValues, executionTimes_mult_int, marker='o', label='mult_int')

plt.plot(numOperationsValues, executionTimes_div_float, marker='o', label='div_float')
plt.plot(numOperationsValues, executionTimes_div_int, marker='o', label='div_int')

plt.title('Temps d\'exécution en fonction du nombre d\'opérations avec le flag -O2')
plt.xlabel('Nombre d\'opérations')
plt.ylabel('Temps moyen (secondes)')
plt.xscale('log')
plt.grid()
plt.legend()
plt.show()