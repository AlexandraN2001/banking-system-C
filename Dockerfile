# Use a base image with C++ support
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source file to /app in the container
COPY . /app

# Compile the source file
RUN g++ -o BankAccountApp BankingSystem.cpp

# Set the default command to run the application
CMD ["./BankAccountApp"]
