import matplotlib.pyplot as plt

# Les valeurs de numOperations que vous avez testées
numOperationsValues = [1e7, 1e8, 1e9]

# Les temps d'exécution correspondants que vous avez collectés
executionTimes_u_o0 = [0.389, 3.818, 38.361]  # Remplacez ces valeurs par les temps réels que vous avez mesurés
executionTimes_ufast_o0 = [0.042, 0.531, 5.589]

executionTimes_opti_o0 = [0.034, 0.269, 2.659]  # Remplacez ces valeurs par les temps réels que vous avez mesurés




# Tracer le graphique
plt.plot(numOperationsValues, executionTimes_u_o0, marker='o', label='sans optimisation')
plt.plot(numOperationsValues, executionTimes_ufast_o0, marker='o', label="1er niveau d'optimisation")

plt.plot(numOperationsValues, executionTimes_opti_o0, marker='o', label="2e niveau d'opitimisation")


plt.title('Temps d\'exécution en fonction du nombre d\'opérations')
plt.xlabel('Nombre d\'opérations')
plt.ylabel('Temps moyen (secondes)')
plt.xscale('log')
plt.grid()
plt.legend()
plt.show()