import random
import time

# Simulate traffic density for 4 lanes
def get_traffic_density():
    return {
        "Lane 1": random.randint(0, 20),
        "Lane 2": random.randint(0, 20),
        "Lane 3": random.randint(0, 20),
        "Lane 4": random.randint(0, 20)
    }

def assign_green_signal(traffic_data):
    # Find lane with highest traffic
    max_lane = max(traffic_data, key=traffic_data.get)
    max_density = traffic_data[max_lane]
    
    # Green time proportional to density
    green_time = 5 + (max_density // 2)
    
    return max_lane, green_time

def main():
    print("🚦 Smart Traffic Light System Simulation Started 🚦\n")
    
    while True:
        traffic_data = get_traffic_density()
        
        print("Current Traffic Density:")
        for lane, density in traffic_data.items():
            print(f"{lane}: {density} vehicles")
        
        max_lane, green_time = assign_green_signal(traffic_data)
        
        print(f"\n➡ Green signal assigned to {max_lane}")
        print(f"⏳ Green Duration: {green_time} seconds\n")
        
        time.sleep(5)
        print("--------------------------------------------------\n")

if __name__ == "__main__":
    main()
