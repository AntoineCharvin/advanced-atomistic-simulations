import matplotlib.pyplot as plt

# Les valeurs de numOperations que vous avez testées
numOperationsValues = [10, 20, 50, 100, 150, 200]

# Les temps d'exécution correspondants que vous avez collectés
executionTimes_pasopti = [0.034, 0.199, 1.28, 5.646, 8.198, 14.65]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_opti = [0.03, 0.185, 1.081, 4.871, 7.089, 11.669]




# Tracer le graphique
plt.plot(numOperationsValues, executionTimes_opti, marker='o', label='optimisé')
plt.plot(numOperationsValues, executionTimes_pasopti, marker='o', label='pas optimisé')




# executionTimes_pasopti = [0.036, 0.091, 0.2, 0.424, 0.651, 0.87]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
# executionTimes_opti = [0.011, 0.053, 0.107, 0.222, 0.294, 0.377]




# #Tracer le graphique
# plt.plot(numOperationsValues, executionTimes_opti, marker='o', label='optimisé')
# plt.plot(numOperationsValues, executionTimes_pasopti, marker='o', label='pas optimisé')


plt.title('Temps d\'exécution en fonction de la dimension du tableau')
plt.xlabel('Nombre d\'opérations')
plt.ylabel('Temps moyen (secondes)')
# plt.xscale('log')
plt.grid()
plt.legend()
plt.show()