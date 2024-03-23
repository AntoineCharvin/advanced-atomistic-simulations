import matplotlib.pyplot as plt

# Les valeurs de numOperations que vous avez testées
numOperationsValues = [1e7, 1e8, 1e9, 2e9]

# Les temps d'exécution correspondants que vous avez collectés
executionTimes_add_float = [20, 213, 2129, 4245]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_add_int = [21, 215, 2151, 4302]

executionTimes_mult_float = [20, 211, 2132, 4274]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_mult_int = [20, 214, 2160, 4325]

executionTimes_div_float = [47, 430, 4264, 8490]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_div_int = [35, 364, 3651, 7322]


# Tracer le graphique
plt.plot(numOperationsValues, executionTimes_add_float, marker='o', label='add_float')
plt.plot(numOperationsValues, executionTimes_add_int, marker='o', label='add_int')

plt.plot(numOperationsValues, executionTimes_mult_float, marker='o', label='mult_float')
plt.plot(numOperationsValues, executionTimes_mult_int, marker='o', label='mult_int')

plt.plot(numOperationsValues, executionTimes_div_float, marker='o', label='div_float')
plt.plot(numOperationsValues, executionTimes_div_int, marker='o', label='div_int')

plt.title('Temps d\'exécution en fonction du nombre d\'opérations avec le flag -O0')
plt.xlabel('Nombre d\'opérations')
plt.ylabel('Temps moyen (secondes)')
plt.xscale('log')
plt.grid()
plt.legend()
plt.show()