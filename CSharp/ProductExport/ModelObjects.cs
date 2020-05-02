using System;
using System.Collections.Generic;
using System.Linq;

namespace ProductExport
{
    public class StoreEvent : Product
    {
        public StoreEvent(string name, string type, Store location, Price price) : base(name, type, 0, price)
        {
            SetLocation(location);
        }

        private Store Location { get; set; }

        public void SetLocation(Store store)
        {
            Location = store;
            store.AddStoreEvent(this);
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

        public string Name { get; protected set; }
        public string Id { get; protected set; }
        public int Weight { get; protected set; }
        public Price Price { get; protected set; }

        public virtual bool IsEvent()
        {
            return false;
        }

        public void SaveToDatabase()
        {
            throw new NotImplementedException("missing from this exercise - shouldn't be called from a unit test");
        }
    }

    public class Price
    {
        public Price(double amount, string currencyCode)
        {
            Amount = amount;
            CurrencyCode = currencyCode;
        }

        public double Amount { get; private set; }
        public string CurrencyCode { get; private set; }

        public double GetAmountInCurrency(string currencyCode)
        {
            if (CurrencyCode == currencyCode)
                return Amount;
            else
            {
                throw new NotImplementedException("shouldn't call this from a unit test, it will do a slow db lookup");
            }
        }
    }

    public class Store
    {
        public readonly IList<Product> Stock = new List<Product>();

        public Store(string name, string id, Product[] products)
        {
            this.Name = name;
            this.Id = id;
            this.AddStockedItems(products);
        }

        public string Name { get; private set; }
        public string Id { get; private set; }

        public void AddStockedItems(params Product[] products)
        {
            foreach (var product in products) Stock.Add(product);
        }

        public void AddStoreEvent(StoreEvent storeEvent)
        {
            Stock.Add(storeEvent);
        }

        public void SaveToDatabase()
        {
            throw new NotImplementedException("missing from this exercise - shouldn't be called from a unit test");
        }
    }

    public class Order
    {

        public Order(string id, DateTime dateTime, Store store, Product[] products)
        {
            this.Id = id;
            this.Date = dateTime;
            this.Store = store;
            this.AddProducts(products);
        }

        public string Id { get; private set; }
        public DateTime Date { get; private set; }
        public Store Store { get; private set; }

        public readonly IList<Product> Products = new List<Product>();

        public double TotalDollars()
        {
            return Products.Sum(product => product.Price.GetAmountInCurrency("USD"));
        }

        public void AddProducts(params Product[] products)
        {
            foreach (var product in products) Products.Add(product);
        }

        public void SaveToDatabase()
        {
            throw new NotImplementedException("missing from this exercise - shouldn't be called from a unit test");
        }
    }
}
