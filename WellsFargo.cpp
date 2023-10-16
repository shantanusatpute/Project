package entities;

import javax.persistence.*;
import java.util.List;

@Entity
public class FinancialAdvisor {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    @OneToMany(mappedBy = "financialAdvisor", cascade = CascadeType.ALL)
    private List<Client> clients;

    // Constructors, Getters, and Setters
}
package entities;

import javax.persistence.*;
import java.util.List;

@Entity
public class Client {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    @ManyToOne
    @JoinColumn(name = "advisor_id")
    private FinancialAdvisor financialAdvisor;

    @OneToMany(mappedBy = "client", cascade = CascadeType.ALL)
    private List<Portfolio> portfolios;

    // Constructors, Getters, and Setters
}
package entities;

import javax.persistence.*;
import java.util.List;

@Entity
public class Portfolio {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne
    @JoinColumn(name = "client_id")
    private Client client;

    @OneToMany(mappedBy = "portfolio", cascade = CascadeType.ALL)
    private List<Security> securities;

    // Constructors, Getters, and Setters
}
package entities;

import javax.persistence.*;
import java.util.Date;

@Entity
public class Security {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;
    private String category;
    private Date purchaseDate;
    private double purchasePrice;
    private int quantity;

    @ManyToOne
    @JoinColumn(name = "portfolio_id")
    private Portfolio portfolio;

    // Constructors, Getters, and Setters
}
package your.package.name;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class FinancialManagementSystemApplication {

    public static void main(String[] args) {
        SpringApplication.run(FinancialManagementSystemApplication.class, args);
    }
}
