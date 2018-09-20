using System;
using System.Collections.Generic;

namespace export
{
    public class StoreEvent : Product
    {
        public StoreEvent(string name, string type, Store store, Price price) : base(name, type, 0, price)
        {
            SetLocation(store);
        }

        private Store Store { get; set; }

        public void SetLocation(Store store)
        {
            Store = store;
            store.AddStockedItems(this);
        }

        public override bool IsEvent()
        {
            return true;
        }
    }

    public class Product
    {
        public Product(string name, string type, int weight, Price price)
        {
            Name = name;
            Id = type;
            Weight = weight;
            Price = price;
        }

        public string Name { get; set; }
        public string Id { get; set; }
        public int Weight { get; set; }
        public Price Price { get; set; }

        public virtual bool IsEvent()
        {
            return false;
        }
    }

    public class Price
    {
        public Price(double amount, string currency)
        {
            Amount = amount;
            Currency = currency;
        }

        public double Amount { get; set; }
        public string Currency { get; set; }

        public double GetAmountInCurrency(string currency)
        {
            return Amount;
        }
    }

    public class Store
    {
        public readonly IList<Product> Stock = new List<Product>();
        public string Name { get; set; }
        public string Id { get; set; }


        public void AddStockedItems(params Product[] products)
        {
            foreach (var product in products) Stock.Add(product);
        }
    }

    public class Order
    {
        public readonly IList<Product> Products = new List<Product>();

        public string Id { get; set; }
        public DateTime Date { get; set; }
        public Store Store { get; set; }

        public double TotalDollars()
        {
            return 0;
        }
    }
}