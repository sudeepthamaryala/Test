# 1. Build the WAR (on host, not in Docker)
mvn clean package

# 2. Build the image (Q5)
docker build -t vehiclerentalapp:v1 .
docker images                     # verify it exists

# 3. Run the container — Q6(a): map host port : container port
docker run -d -p 8080:8080 --name vrentalapp vehiclerentalapp:v1
# container port is 8080 because that's what Tomcat listens on / what you EXPOSEd

# 4. Verify running + access app — Q6(b)
docker ps                         # STATUS should say "Up"
# browser: http://localhost:8080/VehicleRentalManagement/index.jsp

# 5. Tag with YOUR Docker Hub username — Q6(c)
docker tag vehiclerentalapp:v1 yourdockerhubusername/vehiclerentalapp:v1

# 6. Log in
docker login
# prompts for Docker Hub username + password (or access token)

# 7. Push
docker push yourdockerhubusername/vehiclerentalapp:v1

# 8. Verify it's on Docker Hub — Q6(d)
# Open browser: hub.docker.com/r/yourdockerhubusername/vehiclerentalapp
# OR from a different machine/terminal: docker pull yourdockerhubusername/vehiclerentalapp:v1
