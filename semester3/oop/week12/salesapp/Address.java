package salesapp;

class Address {
  private String country;
  private String province;
  private String street;

  public Address(String country, String province, String street) {
    setCountry(country);
    setProvince(province);
    setStreet(street);
  }

  public String getCountry() {
    return country;
  }

  public void setCountry(String country) {
    this.country = country;
  }

  public String getProvince() {
    return province;
  }

  public void setProvince(String province) {
    this.province = province;
  }

  public String getStreet() {
    return street;
  }

  public void setStreet(String street) {
    this.street = street;
  }
}
