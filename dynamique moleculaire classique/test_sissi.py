import random

def generate_random_coordinates():
    return random.uniform(-10.0, 10.0), random.uniform(-10.0, 10.0), random.uniform(-10.0, 10.0)

def write_xyz_file(filename, num_particles):
    with open(filename, 'w') as f:
        f.write(f"{num_particles}\n")
        f.write("Atoms. Time = 0.0\n")
        for i in range(num_particles):
            particle_type = "A" if i % 2 == 0 else "B"
            x, y, z = generate_random_coordinates()
            f.write(f"{particle_type} {x:.2f} {y:.2f} {z:.2f}\n")

if __name__ == "__main__":
    write_xyz_file("example.xyz", 1000)
