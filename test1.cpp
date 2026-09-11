FROM tomcat:9.0-jdk17
RUN rm -rf /usr/local/tomcat/webapps/ROOT
COPY target/VehicleRentalManagement.war /usr/local/tomcat/webapps/VehicleRentalManagement.war
EXPOSE 8080
CMD ["catalina.sh", "run"]
