import matplotlib.pyplot as plt

# Les valeurs de numOperations que vous avez testées
numOperationsValues = [1e7, 1e8, 1e9, 2e9]

# Les temps d'exécution correspondants que vous avez collectés
executionTimes_add_float = [20, 212, 2104, 4293]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_add_int = [20, 211, 2114, 4324]

executionTimes_mult_float = [20, 219, 2189, 4245]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_mult_int = [22, 236, 2348, 4324]

executionTimes_div_float = [46, 430, 4238, 8494]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_div_int = [32, 335, 3337, 6682]


# Tracer le graphique
plt.plot(numOperationsValues, executionTimes_add_float, marker='o', label='add_float')
plt.plot(numOperationsValues, executionTimes_add_int, marker='o', label='add_int')

plt.plot(numOperationsValues, executionTimes_mult_float, marker='o', label='mult_float')
plt.plot(numOperationsValues, executionTimes_mult_int, marker='o', label='mult_int')

plt.plot(numOperationsValues, executionTimes_div_float, marker='o', label='div_float')
plt.plot(numOperationsValues, executionTimes_div_int, marker='o', label='div_int')

plt.title('Temps d\'exécution en fonction du nombre d\'opérations')
plt.xlabel('Nombre d\'opérations')
plt.ylabel('Temps moyen (secondes)')
plt.xscale('log')
plt.grid()
plt.legend()
plt.show()